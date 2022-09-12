<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="3">
		<v-card-title>
			<v-row>
				<v-col cols="8">
					<div>{{tag.Cpt}}</div>
				</v-col>
				<v-col cols="4" align="end">
					&#160;
					<v-btn
						v-if="statshr.srefIxWzskVExpstate=='regd'"
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
					&#160;&#160;
					&#160;
					<v-btn
						v-if="statshr.srefIxWzskVExpstate=='mind'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButRegularizeClick')"
						:value="1"
					>
						<v-icon color="white">mdi-plus-circle</v-icon>
					</v-btn>
					&#160;
					<v-btn
						v-if="statshr.srefIxWzskVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButMinimizeClick')"
						:value="1"
					>
						<v-icon color="white">mdi-minus-circle</v-icon>
					</v-btn>
				</v-col>
			</v-row>
		</v-card-title>

		<v-card-text
			v-if="statshr.srefIxWzskVExpstate=='regd'"
		>
			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtCst"
				:label="tag.CptCst"
			/>

			<v-divider/>

			<h3
				class="text-5 my-1"
			>
				{{tag.HdgDio}}
			</h3>

			<div
				class="my-1"
				style="height:200px"
			>
				<!-- IP divDat - INSERT -->
			</div>

			<v-divider/>

			<h3
				class="text-5 my-1"
			>
				{{tag.HdgCex}}
			</h3>

			<v-select
				class="my-1"
				v-model="contapp.fiFPupCmd"
				:items="feedFPupCmd"
				:label='tag.CptCmd'
				v-on:change="handlePupChange('numFPupCmd', contapp.fiFPupCmd)"
			>
				<template v-slot:selection="{item}">{{item.tit1}}</template>
				<template v-slot:item="{item}">{{item.tit1}}</template>
			</v-select>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfCsq"
				:label="tag.CptCsq"
			/>

			<v-row class="my-1">
				<v-col>
					<v-btn
						v-on:click="handleButClick('ButSmtClick')"
						:disabled="!statshr.ButSmtActive"
						class="my-1"
						color="primary"
					>
						{{tag.ButSmt}}
					</v-btn>
				</v-col>
			</v-row>

		</v-card-text>
	</v-card>
</template>

<script>
	import Wzsk from '../../scripts/Wzsk';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWzskLlvTermClnxevb',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWzskLlvTermClnxevb.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWzskLlvTermClnxevbDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWzskLlvTermClnxevb"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWzskLlvTermClnxevbData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWzskLlvTermClnxevbData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWzskLlvTermClnxevb) this.contiac = dpcheng.ContIacWzskLlvTermClnxevb;
				if (dpcheng.ContInfWzskLlvTermClnxevb) this.continf = dpcheng.ContInfWzskLlvTermClnxevb;
				if (dpcheng.FeedFPupCmd) this.feedFPupCmd = dpcheng.FeedFPupCmd;
				if (dpcheng.StatShrWzskLlvTermClnxevb) this.statshr = dpcheng.StatShrWzskLlvTermClnxevb;
				if (dpcheng.TagWzskLlvTermClnxevb) {
					Wzsk.unescapeBlock(dpcheng.TagWzskLlvTermClnxevb);
					this.tag = dpcheng.TagWzskLlvTermClnxevb;
				}
				if (dpcheng.ContIacWzskLlvTermClnxevb) {
					for (let i = 0; i < this.feedFPupCmd.length; i++)
						if (this.feedFPupCmd[i].num == this.contiac.numFPupCmd) {
							this.contapp.fiFPupCmd = this.feedFPupCmd[i];
							break;
						}
				}
				if (dpcheng.ContInfWzskLlvTermClnxevb) {
					if (!this.continf.ButClaimOn) this.contapp.ButClaimOn = 0;
					else this.contapp.ButClaimOn = 1;
				}
				/*
				<!-- IP mergeDpchEngData - END -->
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
				if (srefIxWzskVDpch == "DpchEngWzskLlvTermClnxevbData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWzskVDpch == "DpchEngWzskLlvTermClnxevbData") this.mergeDpchEngData(obj.dpcheng);
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
			contiac: null,

			continf: null,

			feedFPupCmd: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupCmd: null,

				ButClaimOn: 0,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
