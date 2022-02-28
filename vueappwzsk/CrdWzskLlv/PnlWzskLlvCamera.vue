<template>
	<v-card v-if=initdone class="pa-3 my-3 mx-auto" elevation="4">
		<v-card-title>
			<v-row>
				<v-col cols="11">
					<div>{{tag.Cpt}}</div>
				</v-col>
				<v-col align="end">
					<v-btn-toggle v-model="contapp.ButClaimOn">
						<v-btn
							fab
							small
							light
							color="primary"
							v-on:click="handleButClick('ButClaimClick')"
							:value="1"
							:disabled="!statshr.ButClaimActive"
						>
							<v-icon color="white">{{contapp.ButClaimOn ? 'mdi-cog' : 'mdi-cog-off'}}</v-icon>
						</v-btn>
					</v-btn-toggle>
				</v-col>
			</v-row>
		</v-card-title>

		<v-card-text>
			<v-select
				class="my-2"
				v-model="contapp.fiFPupMde"
				:items="FeedFPupMde"
				:label='tag.CptMde'
				v-on:change="handlePupChange('numFPupMde', fiFPupMde)"
				:disabled="!statshr.PupMdeActive"
			>
				<template v-slot:selection="{item}">{{item.tit1}}</template>
				<template v-slot:item="{item}">{{item.tit1}}</template>
			</v-select>

			<div
				class="my-2"
				style="height:480px"
			>
				<!-- IP divImg - INSERT -->
			</div>

			<v-row class="my-2">
				<v-col>
					<v-btn
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButPlayClick')"
						:disabled="!statshr.ButPlayActive"
					>
						<v-icon color="white">mdi-play</v-icon>
					</v-btn>
					&#160;
					<v-btn
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButStopClick')"
						:disabled="!statshr.ButStopActive"
					>
						<v-icon color="white">mdi-stop</v-icon>
					</v-btn>
				</v-col>
			</v-row>

			<v-divider/>

			<v-checkbox
				class="my-2"
				v-model="contiac.ChkAex"
				v-on:change='updateEng(["contiac"])'
				:label="tag.ChkAex"
				:disabled="!statshr.ChkAexActive"
			/>

			<v-slider
				class="my-2"
				v-model="contiac.SldExt"
				v-on:end='updateEng(["contiac"])'
				:label="tag.CptExt"
				:min="statshr.SldExtMin"
				:max="statshr.SldExtMax"
				:disabled="!statshr.SldExtActive"
			>
				<template v-slot:append>
					<v-text-field
						v-model="contiac.SldExt"
						v-on:change='updateEng(["contiac"])'
						class="mt-0 pt-0"
						hide-details
						single-line
						type="number"
						style="width: 80px"
					/>
				</template>
			</v-slider>

			<v-slider
				class="my-2"
				v-model="contiac.SldFcs"
				v-on:end='updateEng(["contiac"])'
				:label="tag.CptFcs"
				:min="statshr.SldFcsMin"
				:max="statshr.SldFcsMax"
				:disabled="!statshr.SldFcsActive"
			>
				<template v-slot:append>
					<v-text-field
						v-model="contiac.SldFcs"
						v-on:change='updateEng(["contiac"])'
						class="mt-0 pt-0"
						hide-details
						single-line
						type="number"
						style="width: 80px"
					/>
				</template>
			</v-slider>

		</v-card-text>
	</v-card>
</template>

<script>
	import Wzsk from '../../scripts/Wzsk';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWzskLlvCamera',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWzskLlvCamera.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWzskInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit('request', {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - INSERT -->
			*/

			handleButClick: function(consref) {
				const dpchapp = {
					"DpchAppWzskLlvCameraDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": consref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handlePupChange: function(cisref, fi) {
				this.contiac[cisref] = fi.num;

				this.updateEng(["contiac"]);
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWzskLlvCamera"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWzskLlvCameraData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWzskLlvCameraData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContIacWzskLlvCamera) this.contiac = dpcheng.ContIacWzskLlvCamera;
				if (dpcheng.ContInfWzskLlvCamera) this.continf = dpcheng.ContInfWzskLlvCamera;
				if (dpcheng.feedFPupMde) this.feedFPupMde = dpcheng.feedFPupMde;
				if (dpcheng.StatShrWzskLlvCamera) this.statshr = dpcheng.StatShrWzskLlvCamera;
				if (dpcheng.TagWzskLlvCamera) {
					Wzsk.unescapeBlock(dpcheng.TagWzskLlvCamera);
					this.tag = dpcheng.TagWzskLlvCamera;
				};

				if (dpcheng.ContIacWzskLlvCamera) {
					for (var i = 0; i < this.FeedFPupMde.length; i++)
						if (this.FeedFPupMde[i].num == this.contiac.numFPupMde) {
							this.contapp.fiFPupMde = this.FeedFPupMde[i];
							break;
						}
				}

				if (dpcheng.ContInfWzskLlvCamera) {
					if (!this.continf.ButClaimOn) this.contapp.ButClaimOn = 0;
					else this.contapp.ButClaimOn = 1;
				}
				/*
				*/
			},

			handleReply: function(obj) {
				if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);
				else if (obj.then == "handleDpchAppDataDoReply") this.handleDpchAppDataDoReply(obj.srefIxWzskVDpch, obj.dpcheng);
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleDpchAppDataDoReply: function(srefIxWzskVDpch, dpcheng) {
				if (srefIxWzskVDpch == "DpchEngWzskLlvCameraData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/

			handleDpchEngLive: function(dpcheng) {
				/*
				<!-- IP handleDpchEngLive - INSERT -->
				*/
			},
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWzskVDpch == "DpchEngWzskLlvCameraData") this.mergeDpchEngData(obj.dpcheng);
				else if (obj.srefIxWzskVDpch == "DpchEngWzskLlvCameraLive") this.handleDpchEngLive(obj.dpcheng);
				/*
				*/
			}
		},

		computed: {
		},

		data: () => ({
			initdone: false,

			/*
			*/
			contapp: {
				fiFPupMde: null,

				ButClaimOn: 0,
			},

			contiac: null,

			continf: null,

			feedFPupMde: null,

			statshr: null,

			tag: null,
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
