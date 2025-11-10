<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="3">
		<v-card-title>
			<v-row>
				<v-col cols="8">
					<div>{{tag.Cpt}}</div>
				</v-col>
				<v-col cols="4" align="end">
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
				v-model="continf.TxtCtp"
				:label="tag.CptCtp"
			/>

			<v-divider/>

			<div
				class="my-1"
				style="height:250px"
			>
				<!-- IP divPlt - INSERT -->
			</div>

			<v-divider/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtDhr"
				:label="tag.CptDhr"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtDhw"
				:label="tag.CptDhw"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtDrr"
				:label="tag.CptDrr"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtDrw"
				:label="tag.CptDrw"
			/>

		</v-card-text>
	</v-card>
</template>

<script>
	import Wzsk from '../../scripts/Wzsk';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWzskLlvSysmon',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWzskLlvSysmon.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWzskLlvSysmonDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": consref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWzskLlvSysmon"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWzskLlvSysmonData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWzskLlvSysmonData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContInfWzskLlvSysmon) this.continf = dpcheng.ContInfWzskLlvSysmon;
				if (dpcheng.StatShrWzskLlvSysmon) this.statshr = dpcheng.StatShrWzskLlvSysmon;
				if (dpcheng.TagWzskLlvSysmon) {
					Wzsk.unescapeBlock(dpcheng.TagWzskLlvSysmon);
					this.tag = dpcheng.TagWzskLlvSysmon;
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
				if (srefIxWzskVDpch == "DpchEngWzskLlvSysmonData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/

			handleDpchEngWzskLlvSysmonLive: function(dpcheng) {
				/*
				<!-- IP handleDpchEngWzskLlvSysmonLive - BEGIN -->
				*/
				console.log("PnlWzskLlvSysmon.handleDpchEngWzskLlvSysmonLive()" + dpcheng);
				/*
				<!-- IP handleDpchEngWzskLlvSysmonLive - END -->
				*/
			},
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWzskVDpch == "DpchEngWzskLlvSysmonData") this.mergeDpchEngData(obj.dpcheng);
				else if (obj.srefIxWzskVDpch == "DpchEngWzskLlvSysmonLive") this.handleDpchEngWzskLlvSysmonLive(obj.dpcheng);
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
			continf: null,

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
